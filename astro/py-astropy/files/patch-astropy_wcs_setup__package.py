--- astropy/wcs/setup_package.py.orig	2016-07-02 18:53:24 UTC
+++ astropy/wcs/setup_package.py
@@ -244,8 +244,7 @@ def get_wcslib_cfg(cfg, wcslib_files, in
                 '-Wno-strict-prototypes',
                 '-Wno-unused-function',
                 '-Wno-unused-value',
-                '-Wno-uninitialized',
-                '-Wno-unused-but-set-variable'])
+                '-Wno-uninitialized'])
 
 
 
