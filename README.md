### ZenGames

A template to start making games in Pascal with the [ZenGL](http://zengl.org) game engine and the [MondoZenGL](http://zengl.org/forum/index.php/topic,158.0.html) framework.

Include all sources from ZenGL and MondoZenGL, except the demos and extras.

This is **not** a tutorial of the ZenGL API

For the documentation of ZenGL and MondoZenGL use the respective websites.

### How do I start new project?

  1) Clone the repo:

  ```bash

  git clone https://git.disroot.org/daltomi/ZenGames.git MySuperGame

  cd MySuperGame

  ```

  2) Read and modify the `Makefile` file according to your needs.


### Support

```bash
Platform      : GNU/Linux(i386, x86_64)

Language      : Object Pascal

Compiler      : Free Pascal >= 3.0

Build
  - By default, the architecture is 64 bits.
  * Release       : make
  * Debug         : make debug
  * Clean         : make clean
  * Packbin       : make PACKBIN=1

  - To compile in a 32 bits architecture use:
  *               : ARCH=i386 make [options]
```

External projects that may be useful:

* [ZenGL tools](http://zengl.org/download.html)

* [ZenGL extras](http://zengl.org/extra.html)

