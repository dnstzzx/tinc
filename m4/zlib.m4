dnl Check to find the zlib headers/libraries

AC_DEFUN(tinc_ZLIB,
[
  tinc_ac_save_CPPFLAGS="$CPPFLAGS"

  AC_ARG_WITH(zlib,
    AC_HELP_STRING([--with-zlib=DIR], [zlib base directory, or:]),
    [zlib="$withval"
     CFLAGS="$CFLAGS -I$withval/include"
     CPPFLAGS="$CPPFLAGS -I$withval/include"
     LIBS="$LIBS -L$withval/lib"]
  )

  AC_ARG_WITH(zlib-include,
    AC_HELP_STRING([--with-zlib-include=DIR], [zlib headers directory]),
    [zlib_include="$withval"
     CFLAGS="$CFLAGS -I$withval"
     CPPFLAGS="$CPPFLAGS -I$withval"]
  )

  AC_ARG_WITH(zlib-lib,
    AC_HELP_STRING([--with-zlib-lib=DIR], [zlib library directory]),
    [zlib_lib="$withval"
     LIBS="$LIBS -L$withval"]
  )

  AC_CHECK_HEADERS(zlib.h,
    [],
    [AC_MSG_ERROR("zlib header files not found."); break]
  )

  CPPFLAGS="$tinc_ac_save_CPPFLAGS"

  AC_CHECK_LIB(z, compress2,
    [LIBS="$LIBS -lz"],
    [AC_MSG_ERROR("zlib libraries not found.")]
  )
])
