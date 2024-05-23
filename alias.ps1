function ssh {
    param (
        [string]$userHost
    )

    $user, $host = $userHost -split '@'
    Write-Output "Connected to HPC facility..."
    docker compose exec -u $user -w /home/$user $host bash
}

function start {
    docker compose up -d
}

function stop {
    docker compose down
}

function status {
    docker compose ps
}
