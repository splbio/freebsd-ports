--- ui/views/bubble/bubble_delegate.cc.orig	2016-05-11 19:02:36 UTC
+++ ui/views/bubble/bubble_delegate.cc
@@ -96,7 +96,7 @@ Widget* BubbleDelegateView::CreateBubble
   // the parent frame and let DWM handle compositing.  If not, then we don't
   // want to allow the bubble to extend the frame because it will be clipped.
   bubble_delegate->set_adjust_if_offscreen(ui::win::IsAeroGlassEnabled());
-#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX)
+#elif (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_MACOSX) || defined(OS_BSD)
   // Linux clips bubble windows that extend outside their parent window bounds.
   // Mac never adjusts.
   bubble_delegate->set_adjust_if_offscreen(false);
