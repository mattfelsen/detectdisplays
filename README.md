# detectdisplays
A command-line tool for Macs that detects attached displays.

Sometimes on a Mac, not all attached displays are immediately detected (such as if you open the lid on a MacBook Pro while attached to an external monitor or if you boot a Mac on a KVM while it isn't the active device). This tool has the same effect as clicking "Detect Displays" in the "Displays" System Preferences pane, making it suitable for a [LaunchAgent](https://github.com/mattfelsen/detectdisplays/wiki) to detect displays at login.

**Note:** This repo was ported from [Google Code](https://code.google.com/p/detectdisplays/) and I am not the author. However, I have verified this working under OS X 10.10.1, built against the 10.9 SDK, on a MacBook Air using a Mini DisplayPort -> VGA adapter.
