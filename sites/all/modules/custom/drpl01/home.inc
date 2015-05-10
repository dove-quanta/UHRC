<?php
module_load_include('inc', 'drpl01', 'criteria');
module_load_include('inc', 'drpl01', 'discussion');
function home()
{
    global $base_url;
#header start - write function to generate header
    $data = get_criteria();
#header end
    $data .= "<div class='row ohrc-container'>";
    $data .= "<div class='col-md-8'>";
    $data .= "<div style='width:100%'>";
    $data .= "<h4 style='color:#0077c0;font-weight:bold;'>Recent updates</h4>";
    $data .= "
    <table style='width:100%;border-width:1px;border-color:#0077c0;border-style:solid;'><tr><td>
    <img src='" . "/sites/all/themes/Sarai/images/recommend.jpg" . "' style='width:100%;'/></td>
    <td style='width:80%'><div style='width:70%;float:left'>
                            <p><a href='http://www.uhrc.ug/latest-annual-report/' target='_blank'>The latest report on the National Human Rights Index for Uganda</a></p>
                        </div></td></tr></table>";
    $data .= "</div>";
    $data .= "<div style='width:50%;float:left;'>";
    $data .= "<h4 class='ohrc-page-h4'>How to use this tool</h4>";
    $data .= "<div  class='ohrc-box' >
                            <p>The database provides easy access to country specific
                                human rights information emanating from
                                international human rights mechanisms</p>
                                <a href=\"content/how-use-tool-0?iframe=no\" class=\"read-more\">more &gt;&gt;</a>
                            </div>";
    $data .= "</div>";
    $data .= "<div style='width:50%;float:right;'><h4 class='ohrc-page-h4'>About the database</h4>";
    $data .= "<div  class='ohrc-box' >
                            <p>The database provides easy access to country specific
                                human rights information emanating from
                                international human rights mechanisms</p>
                                <a href=\"about-us-test\">more &gt;&gt;</a>
                            </div>";
    $data .= "</div>";
    $data .= "<div  style='width:50%;float:left;'><h4 class='ohrc-page-h4'>Answer to FAQs</h4>";
    $data .= "<div  class='ohrc-box' >
                            <p>The database provides easy access to country specific
                                human rights information emanating from
                                international human rights mechanisms</p>
                                <a href=\"content/answer-faqs?iframe=no\" class=\"read-more\">more &gt;&gt;</a>
                            </div>";
    $data .= "</div>";
    $data .= "<div style='width:50%;float:right;'><h4 class='ohrc-page-h4'>Background info</h4>";
    $data .= "<div  class='ohrc-box' >
                            <p>The database provides easy access to country specific
                                human rights information emanating from
                                international human rights mechanisms</p>
                                <a href=\"content/background-info?iframe=no\" class=\"read-more\">more &gt;&gt;</a>
                            </div>";
    $data .= "</div>";
    $data .= "</div>";
    $data .= "<div class='col-md-4'>";
    $data .= "<div style='width:100%;'>";
    $data .= get_discussions();
    $data .= "</div>";
    $data .= "</div>";
    $data .= "<div class='row'>";
    $data .= "<div class='col-md-12'><div style='margin-left:auto;margin-right:auto;width:30%'><a id='ohrc-logo' href='http://www.ohchr.org' style='margin-left:auto;margin-right:auto;width:80%'><img src='" . $base_url . "/sites/all/themes/Sarai/images/ohrc.jpg' /></a></div></div>";
    $data .= "</div>";
    $data .= "</div>";
    $page = array(
        '#markup' => $data,
    );
    return $page;
}
