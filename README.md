This is a personal usage repository for Galaxy S4 Kernel customization by Amoonhappy.

Implemented enhancements:
1. 64G exFAT sdcard support
2. USB charger speed increase from 600mA to 800mA
3. Disable some debug
4. Disable zRAM and SWAP for better battery life
5. add kernel built-in CPU governor (interactive, conservative etc)
6. add Simple I/O (sio) Scheduler
7. enable CIFS/NFS filesystem
8. New Arizona (WM5102) platform drivers. (Thanks to AndreiLux)
9. Minor tuning on the big.LITTLE switch param, the CPU will switch to A7 cores a bit faster than stock kernel
10.enable ARM CPU topology (SCHED_MC default 0)
11.enable dynamic CPU hotplug
12.enable arizona haptics
13.enable USB OTG

Todo:
1. battery drain testing for 10-11
2. init.d support
3. unfinished OC for A15 cores
4. CPU undervolting 
5. bus, mem, LCD, undervolting stablization testing
6. PowerVR SGX544MP3 OC & UV
