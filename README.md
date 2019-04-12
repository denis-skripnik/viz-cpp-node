# Introducing VIZ

[![Build Status](https://travis-ci.org/VIZ-World/viz-world.svg?branch=master)](https://travis-ci.org/VIZ-World/viz-world)

VIZ is an DPOS blockchain with an unproven consensus algorithm (Fair DPOS with witness penalty for missing block).

# No Support & No Warranty

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
IN THE SOFTWARE.

# Code is Documentation

Rather than attempt to describe the rules of the blockchain, it is up to
each individual to inspect the code to understand the consensus rules.

# Building

See [documentation/building.md](documentation/building.md) for detailed build instructions, including
compile-time options, and specific commands for Linux (Ubuntu LTS) or macOS X.

## Dockerized p2p Node

Just want to get up and running quickly?  Try deploying a prebuilt
dockerized container.  Both common binary types are included.
To run a p2p node (ca. 2GB of memory is required at the moment):

    docker run \
        -d -p 2001:2001 -p 8090:8090 --name viz-default \
        viz-world/viz-world

    docker logs -f viz-default  # follow along

## Dockerized Full Node

To run a node with *all* the data (e.g. for supporting a content website)
that uses ca. 14GB of memory and growing:

    docker run \
        --env USE_WAY_TOO_MUCH_RAM=1 \
        -d -p 2001:2001 -p 8090:8090 --name viz-full \
        viz-world/viz-world

    docker logs -f viz-full

# Seed Nodes

A list of some seed nodes to get you started can be found in
[share/vizd/seednodes](share/vizd/seednodes).

This same file is baked into the docker images and can be overridden by
setting `VIZD_SEED_NODES` in the container environment at `docker run`
time to a whitespace delimited list of seed nodes (with port).
