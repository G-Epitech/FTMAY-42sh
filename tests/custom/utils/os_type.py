import platform

class OSType():
    WINDOWS = 0
    MACOS = 1
    OTHER = 2

    def is_macos() -> bool:
        return platform.system().lower().find("darwin") >= 0
    
    def is_windows(platform: str) -> bool:
        return platform.system().lower().find("windows") >= 0

    def get():
        if (OSType.is_macos()):
            return OSType.MACOS
        elif OSType.is_windows():
            return OSType.WINDOWS
        else:
            return OSType.OTHER
