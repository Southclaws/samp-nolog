# nolog

This is a Linux only plugin for SA:MP that blocks logging to `server_log.txt`.

It was pretty much written by MyU since my C++ is very rusty (no pun intended).

## Why?

Why would you want to block logging to `server_log.txt`?

Because individual log files are not

- scalable
- easily managable
- portable

It's also not standard for a Linux app to log to STDOUT _and_ a file. If I want
to log to a file, I'd just pipe it.

This also removes the IO overhead of writing to the log file - which happens on
the main thread.

With this plugin loaded, all your output comes out of STDOUT and you can do as
you please with it:

- send to local or remote syslog
- let a parent application (such as
  [sampctl](https://github.com/Southclaws/sampctl)) capture it and send it
  somewhere
- send it to Elasticsearch for fast searching
- watch for "error", "warning", "debug" and send an Email or Discord message to
  alert your team to issues
- pipe it to /dev/null and live life on the edge

## Demo/Test

To check out the plugin in action, run `make runtest` if you have Make
available.

If you're on Windows and don't have Make installed, run this:

```powershell
cp nolog.so test\plugins\nolog.so
sampctl package build --forceEnsure --dir test
sampctl server run --dir test --container
```

Requires sampctl and Docker to be installed.

## Why Linux Only?

Linux is the go-to production server, there are very few reasons to run a
production server on Windows. Windows is largely used for development and you'll
likely not care about the overhead of log files in a development environment.

If you _do_ run a prod server on Windows and are still interested in blocking
`server_log.txt` output, unfortunately I don't plan to work on a Windows version
as I'm even entirely sure if it'll work the same way.
