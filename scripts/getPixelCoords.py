import pyautogui # type: ignore
import win32gui # type: ignore
import time

def get_active_window_relative_mouse_pos():
    hwnd = win32gui.GetForegroundWindow()  # Get the handle of the active window
    if hwnd:
        rect = win32gui.GetWindowRect(hwnd)
        x, y = pyautogui.position()
        relative_x = x - rect[0]
        relative_y = y - rect[1]
        return relative_x, relative_y
    else:
        return None

try:
    while True:
        relative_pos = get_active_window_relative_mouse_pos()
        if relative_pos:
            print(f"Mouse position relative to active window: X={relative_pos[0]}, Y={relative_pos[1]}")
        else:
            print("No active window found")

        time.sleep(0.1)
except KeyboardInterrupt:
    print("Script stopped by user.")
