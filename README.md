# nolog

This is a Linux only plugin for SA:MP that blocks logging to `server_log.txt`.

It was pretty much written by MyU since my C++ is very rusty (no pun intended).

## Why?

Why would you want to block logging to `server_log.txt`?

Because individual log files are not

* scalable
* easily managable
* portable

It's also not standard for a Linux app to log to STDOUT _and_ a file. If I want to log to a file, I'd just pipe it.

This also removes the IO overhead of writing to the log file - which happens on the main thread.

With this plugin loaded, all your output comes out of STDOUT and you can do as you please with it:

* send to local or remote syslog
* let a parent application (such as [sampctl](https://github.com/Southclaws/sampctl)) capture it and send it somewhere
* send it to Elasticsearch for fast searching
* watch for "error", "warning", "debug" and send an Email or Discord message to alert your team to issues
* pipe it to /dev/null and live life on the edge
