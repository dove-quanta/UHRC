<?php
global $user;
function router()
{
    global $user;
    $path = request_path();
    switch ($path) {
        case 'front-page':
            $page = array(
                '#markup' => theme('front-page', array()),
            );
            break;
        case '':
            $page = array(
                '#markup' => theme('front-page', array()),
            );
            break;
        case 'uhrcsearch':
            $page = array(
                '#markup' => theme('uhrcsearch', array()),
            );
            break;
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
        case 'mda-dashboard':
        $page = array(
            '#markup' => theme('mda-dashboard', array()),
        );
        break;
        case 'mda-recommendation-table':
            $page = array(
                '#markup' => theme('mda-recommendation-table', array()),
            );
            break;
        case 'admin-recommendation-table':
            $page = array(
                '#markup' => theme('admin-recommendation-table', array()),
            );
            break;
        case 'recommendation-recommendation-table':
            $page = array(
                '#markup' => theme('recommendation-recommendation-table', array()),
            );
            break;
        case 'admin-dashboard':
            $page = array(
                '#markup' => theme('admin-dashboard', array()),
            );
            break;
        case 'dashboard':
           // if (!user_is_logged_in()) {}
            $roles = $user->roles;
            if (in_array('admin', $roles)) {
                $page = array(
                    '#markup' => theme('admin', array()),
                );
            } elseif(in_array('mda', $roles)) {
                $page = array(
                    '#markup' => theme('mda', array()),
                );
            }
            else
            {
                drupal_goto('user');
            }
            break;
        default:
            $page = array(
                '#markup' => "<div>Hello, world</div>",
            );
            break;
    }

    return $page;
}