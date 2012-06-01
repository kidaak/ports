$OpenBSD$
--- src/update.c.orig	Fri Dec  2 10:41:51 2011
+++ src/update.c	Mon Dec  5 20:14:23 2011
@@ -33,7 +33,9 @@
 #include <string.h>
 
 #ifndef WIN32
+#   include <sys/types.h>
 #   include <sys/socket.h>
+#   include <netinet/in.h>
 #   include <sys/time.h>
 #   include <netdb.h>
 #   include <unistd.h>
