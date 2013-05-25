#!/bin/sh
export KERNELDIR=`readlink -f .`
export RAMFS_SOURCE=`readlink -f $KERNELDIR/../ramfs-sgs4-9500`
export PARENT_DIR=`readlink -f ..`
export USE_SEC_FIPS_MODE=true
CROSS_COMPILE=/home/jeff/Desktop/toolchains/arm-eabi-linaro-4.6.2/bin/arm-eabi-

if [ "${1}" != "" ];then
  export KERNELDIR=`readlink -f ${1}`
fi

RAMFS_TMP="/tmp/ramfs-source-sgs4"

if [ ! -f $KERNELDIR/.config ];
then
  make amoonhappy_10_defconfig
fi

. $KERNELDIR/.config

export ARCH=arm
export CROSS_COMPILE=/home/jeff/Desktop/toolchains/arm-eabi-linaro-4.6.2/bin/arm-eabi-

mkdir -p $RAMFS_TMP

cd $KERNELDIR/
nice -n 10 make -j4 || exit 1

#remove previous ramfs files
rm -rf $RAMFS_TMP.cpio
rm -rf $RAMFS_TMP.cpio.gz
#copy ramfs files to tmp directory
cp -ax $RAMFS_SOURCE/* $RAMFS_TMP
#clear git/svn repositories in ramfs
find $RAMFS_TMP -name .svn -exec rm -rf {} \;
#remove empty directory placeholders
find $RAMFS_TMP -name EMPTY_DIRECTORY -exec rm -rf {} \;
rm -rf $RAMFS_TMP/tmp/*
#remove mercurial repository
rm -rf $RAMFS_TMP/.hg
#copy modules into ramfs
mkdir -p $RAMFS_TMP/lib/modules
find -name '*.ko' -exec cp -av {} $RAMFS_TMP/lib/modules/ \;
/home/jeff/Desktop/toolchains/arm-eabi-linaro-4.6.2/bin/arm-eabi-strip --strip-unneeded $RAMFS_TMP/lib/modules/*

cd $RAMFS_TMP
/home/jeff/Desktop/work_9500/mkbootfs . | gzip > $RAMFS_TMP.cpio.gz
ls -lh $RAMFS_TMP.cpio.gz
cd -

nice -n 10 make -j3 zImage || exit 1

./mkbootimg --kernel $KERNELDIR/arch/arm/boot/zImage --ramdisk $RAMFS_TMP.cpio.gz --base 0x10000000 --pagesize 2048  -o $KERNELDIR/boot.img
