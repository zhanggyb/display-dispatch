//
// shell-surface.hpp
//

#ifndef DISPLAY_DISPATCH_SHELL_SURFACE_HPP
#define DISPLAY_DISPATCH_SHELL_SURFACE_HPP

#include "shell.hpp"
#include "surface.hpp"

struct ShellSurface {

  ShellSurface()
      : native(nullptr) {}

  ~ShellSurface() {
    if (native) wl_shell_surface_destroy(native);
  }

  void Setup(const Shell &shell, const Surface &surface) {
    Destroy();
    native = wl_shell_get_shell_surface(shell.native, surface.native);
    wl_shell_surface_add_listener(native, &kListener, this);
  }

  void Destroy() {
    if (native) {
      wl_shell_surface_destroy(native);
      native = nullptr;
    }
  }

  void Pong(uint32_t serial) {
    wl_shell_surface_pong(native, serial);
  }

  void SetToplevel() {
    wl_shell_surface_set_toplevel(native);
  }

  struct wl_shell_surface *native;

  static void OnPing(void *data, struct wl_shell_surface *shell_surface, uint32_t serial);

  static void OnConfigure(void *data,
                          struct wl_shell_surface *shell_surface,
                          uint32_t edges,
                          int32_t width,
                          int32_t height);

  static void OnPopupDone(void *data, struct wl_shell_surface *shell_surface);

  static const wl_shell_surface_listener kListener;
};

#endif //DISPLAY_DISPATCH_SHELL_SURFACE_HPP
