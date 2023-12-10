# rotation
Programmes pour des rendus 2D et 3D avec rotations
Fonctionne sous windows avec le compilateur TCC
Pour le faire fonctionner sur Mac OS ou Linux, utiliser unistd.h au lieu de windows.h et remplacer Sleep(...) par usleep(...)

#Le compiler Sous windows avec TCC :
1. Mettez le dossier tcc (tiny C compiler : https://bellard.org/tcc/) dans le dossier du projet puis ouvrez le dossier avec une invite de commande :
2. tapez ceci :

```batch
tcc\tcc.exe rotation2D.c -o rotation2Dbin.exe && rotation2Dbin.exe
```

La version avec les points dans un repère en 3D est en cours de développement 🤠.
