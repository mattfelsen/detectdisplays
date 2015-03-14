# Introduction #

You can use a LaunchAgent to run **detectdisplays** at login. This is useful if, for instance, your Mac is behind a KVM and you switch to one before logging in.


# Sample LaunchAgent #

To run this LaunchAgent, place this file at <tt>/Library/LaunchAgents/edu.umich.detectdisplays.plist</tt>.

```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
	<key>Label</key>
	<string>edu.umich.detectdisplays</string>
	<key>Program</key>
	<string>/usr/local/bin/detectdisplays</string>
	<key>RunAtLoad</key>
	<true/>
	<key>KeepAlive</key>
	<false/>
</dict>
</plist>
```