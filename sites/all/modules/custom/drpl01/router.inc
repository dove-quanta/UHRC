<?php

function router()
{
    $path = request_path();
    switch ($path) {
        case 'responsible-notifications':
            $page = array(
                '#markup' => theme('responsible-notifications', array()),
            );
            break;
        case 'contributing-notifications':
            $page = array(
                '#markup' => theme('contributing-notifications', array()),
            );
            break;
        default:
            $page = array(
                '#markup' => "<div>Hello, world</div>",
            );
            break;
    }

    return $page;
}