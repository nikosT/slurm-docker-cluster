#!/bin/bash
#SBATCH --job-name=my_openmp_job        # Job name
#SBATCH --output=my_openmp_job_%j.out  # Output file name (%j expands to jobID)
#SBATCH --error=my_openmp_job_%j.err   # Error file name (%j expands to jobID)
#SBATCH --partition=normal          # Partition name
#SBATCH --nodes=1                    # Number of nodes
#SBATCH --ntasks=1                    # Number of tasks
#SBATCH --ntasks-per-node=1          # Number of tasks per node
#SBATCH --cpus-per-task=4          # Number of tasks per node
#SBATCH --time=00:01:00              # Time limit (HH:MM:SS)
##SBATCH --mem=1000

export OMP_NUM_THREADS=$SLURM_CPUS_PER_TASK


$HOME/openmp_examples/ScalabilityTuningRF.py
