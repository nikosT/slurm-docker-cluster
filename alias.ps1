function ssh {
    param (
        [string]$userHost
    )

    $wuser, $whost = $userHost -split '@'
    Write-Output "Connected to HPC facility..."
    docker-compose exec -u $wuser -w /home/$wuser $whost bash
}

function wstart {
    docker-compose up -d
}

function wstop {
    docker-compose down
}

function wstatus {
    docker-compose ps
}
