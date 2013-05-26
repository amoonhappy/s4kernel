This is a personal usage repository for Galaxy S4 Kernel customization by Amoonhappy.<br>

Implemented enhancements:<br>
1. 64G exFAT sdcard support<br>
2. USB charger speed increase from 600mA to 800mA<br>
3. Disable some debug<br>
4. Disable zRAM and SWAP for better battery life<br>
5. add kernel built-in CPU governor (interactive, conservative etc)<br>
6. add Simple I/O (sio) Scheduler<br>
7. enable CIFS/NFS filesystem<br>
8. New Arizona (WM5102) platform drivers. (Thanks to AndreiLux)<br>
9. Minor tuning on the big.LITTLE switch param, the CPU will switch to A7 cores a bit faster than stock kernel<br>
10.enable ARM CPU topology (SCHED_MC default 0)<br>
11.enable dynamic CPU hotplug<br>
12.enable arizona haptics<br>
13.enable USB OTG<br>


Todo:<br>
1. battery drain testing for 10-11<br>
2. init.d support<br>
3. unfinished OC for A15 cores<br>
4. CPU undervolting <br>
5. bus, mem, LCD, undervolting stablization testing<br>
6. PowerVR SGX544MP3 OC & UV<br>
