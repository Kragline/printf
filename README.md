To make the lib just run make in projects directory.

But be careful, if you want to test it on linux you have to change this line of code in ft_puthex.c

  bytes += byte_putstr("0x0");
  
To this

  bytes += byte_putstr("(nil)");
