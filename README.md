A simple application which sits in the Taskbar notification area, and tells how many days since the last restart.

It just puts a simple icon in the notification area. 
For the first 24 hours, it's just a green dot. On the second day, it changes to a yellow dot with a big "1". 
Then "2", "3" and so on up to "9", with the background color changing each day to make it more noticeable. 
On the tenth day, it changes to a star with a red background (I couldn't fit two digits in the icon), 
and stays that way until your reboot (Due to API limitations, the time will restart at zero after 49 days). 
The precise time (days, hours, minutes, seconds) is displayed in the icon tooltip and in the About box.

I wrote this in the 90's in VC++ v6. I've changed nothing other than making sure it compiles in VS2008. 
I figured others may find it useful. It's very handy in data centers, where you have a number of servers running 24x7, 
and want to reboot them every now & then.
