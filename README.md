# CPP Bench operations

Inspired by [nodejs-bench-operations][].

## Setup

- Download and install [Google Benchmark][]
- Preferably, clone the [Google Benchmark][] project parallel to this repository. Otherwise, you will need to adjust the [Makefile][] according to the new path.

## Results

See [RESULTS.md](./RESULTS.MD).

## Compile and run

```console
$ make && ./app
```

Cleanup with

```console
$ make clean
```

[nodejs-bench-operations]: https://github.com/RafaelGSS/nodejs-bench-operations
[Google Benchmark]: https://github.com/google/benchmark#installation
[Makefile]: ./Makefile
