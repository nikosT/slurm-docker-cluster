#!/bin/bash
#SBATCH --job-name=my_tuning        # Job name
#SBATCH --output=my_tuning_%j.out  # Output file name (%j expands to jobID)
#SBATCH --error=my_tuning_%j.err   # Error file name (%j expands to jobID)
#SBATCH --partition=normal          # Partition name
#SBATCH --nodes=1                    # Number of nodes
#SBATCH --ntasks=4                    # Number of tasks
#SBATCH --cpus-per-task=1          # Number of tasks per node
#SBATCH --time=00:01:00              # Time limit (HH:MM:SS)

$HOME/openmp_examples/ScalabilityTuningRF.py
