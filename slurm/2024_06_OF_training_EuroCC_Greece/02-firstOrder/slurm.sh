#!/bin/bash

#SBATCH --job-name=secondOrder        # Job name
#SBATCH --output=simple%j.out        # Stdout (%j expands to jobId)
#SBATCH --error=simple%j.err         # Stderr (%j expands to jobId)
#SBATCH --ntasks=4                  # Total number of tasks
#SBATCH --nodes=2                     # Total number of nodes requested
#SBATCH --ntasks-per-node=2           # Tasks per node
#SBATCH --cpus-per-task=1             # Threads per task(=1) for pure MPI
#SBATCH --mem=500                     # Memory per job in MB
#SBATCH -t 00:04:00                   # Run time (hh:mm:ss) - (max 48h)
#SBATCH --partition=normal           # Submit queue


## LOAD MODULES ##
# clean up loaded modules 
source /usr/lib/openfoam/openfoam2312/etc/bashrc

## RUN YOUR PROGRAM ##
resourcesDir="$FOAM_TUTORIALS"/incompressible/adjointOptimisationFoam/resources
cp -rf "$resourcesDir"/meshes/sbend/polyMesh/ constant/
cp -r 0.orig 0

mkdir -p runlogs

decomposePar > runlogs/log.decomposePar 2>&1 
srun simpleFoam -parallel > runlogs/log.simple       2>&1
