# minitalk

A simple inter-process communication project in C using UNIX signals.

## Overview

**minitalk** is a minimalist communication system between two processes: a server and a client. It demonstrates message passing using Unix signals (`SIGUSR1` and `SIGUSR2`) to transmit data, typically as binary sequences representing characters.

## Features

- **Server Process**: Listens for signals, reconstructs characters bit by bit, and prints received messages.
- **Client Process**: Sends strings to the server by encoding each character as a series of signals.
- **Reliable Transmission**: Handles arbitrary message lengths, sending messages one bit at a time.
- **Basic Error Handling**: Checks for valid PID and message input.
- **Clean Exit**: Server and client can terminate gracefully.

## Getting Started

### Prerequisites

- GCC or Clang (C compiler)
- Unix-like operating system (Linux, macOS, WSL)

### Build

```sh
make
```

This produces two executables: `server` and `client`.

### Usage

Start the server in one terminal:
```sh
./server
```
It will print its PID.

Send a message from the client (in another terminal):
```sh
./client <server_pid> "Your message here"
```
Replace `<server_pid>` with the actual PID shown by the server.

Example:
```sh
./client 12345 "Hello, world!"
```

## Project Structure

- `server.c` - Source for the server process.
- `client.c` - Source for the client process.
- `Makefile` - Build instructions.
- `README.md` - Project documentation.

## Notes

- Only ASCII characters are reliably transmitted.
- This project is for educational purposes and does not implement advanced error correction or transmission speed optimizations.

## Author

- [oait-h-m](https://github.com/oait-h-m)
