import pyautogui
import win32gui
import time

def get_active_window_relative_mouse_pos():
    # Get the active window
    hwnd = win32gui.GetForegroundWindow()  # Get the handle of the active window
    if hwnd:
        # Get window's rect (position and size)
        rect = win32gui.GetWindowRect(hwnd)
        x, y = pyautogui.position()  # Get the current mouse position
        relative_x = x - rect[0]  # Subtract the window's top-left x
        relative_y = y - rect[1]  # Subtract the window's top-left y
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

        time.sleep(0.1)  # Sleep for 100ms before checking again (adjust the interval as needed)
except KeyboardInterrupt:
    print("Script stopped by user.")
