<?php
global $base_url;
module_load_include('inc', 'drpl01', 'criteria');
module_load_include('inc', 'drpl01', 'discussion');
?>
<div class='row ohrc-container'>
    <div class="col-md-12">
        <div class='ohrc-search-criteria'>
            <div id='ohrc-search-header'>Searchable Criteria</div>
            <form class="navbar-form navbar-left" role="search" id='ohrc-form-criteria' action='uhrcsearch'>
                <?php
                print get_mechanisms();
                print get_years();
                print get_thematic_areas();
                print get_mdas();
                ?>
                <button type="submit" class="btn btn-default">Go</button>
            </form>
        </div>
    </div>
</div>
<div class='row ohrc-container'>
    <div class='col-md-8'>
        <div style='width:100%'>
            <h4 style='color:#0077c0;font-weight:bold;'>Recent updates</h4>

            <table style='width:100%;border-width:1px;border-color:#0077c0;border-style:solid;'>
                <tr>
                    <td>
                        <img src='/sites/all/themes/Sarai/images/recommend.jpg' style='width:100%;'/></td>
                    <td style='width:80%'>
                        <div style='width:70%;float:left'>
                            <p><a href='http://www.uhrc.ug/latest-annual-report/' target='_blank'>The latest report on
                                    the National Human Rights Index for Uganda</a></p>
                        </div>
                    </td>
                </tr>
            </table>
        </div>
        <div style='width:50%;float:left;'>
            <h4 class='ohrc-page-h4'>How to use this tool</h4>

            <div class='ohrc-box'>
                <p>The database provides easy access to country specific
                    human rights information emanating from
                    international human rights mechanisms</p>
                <a href="content/how-use-tool-0?iframe=no" class="read-more">more &gt;&gt;</a>
            </div>
        </div>
        <div style='width:50%;float:right;'><h4 class='ohrc-page-h4'>About the database</h4>

            <div class='ohrc-box'>
                <p>The database provides easy access to country specific
                    human rights information emanating from
                    international human rights mechanisms</p>
                <a href="about-us-test">more &gt;&gt;</a>
            </div>
        </div>
        <div style='width:50%;float:left;'><h4 class='ohrc-page-h4'>Answer to FAQs</h4>

            <div class='ohrc-box'>
                <p>The database provides easy access to country specific
                    human rights information emanating from
                    international human rights mechanisms</p>
                <a href="content/answer-faqs?iframe=no" class="read-more">more &gt;&gt;</a>
            </div>
        </div>
        <div style='width:50%;float:right;'><h4 class='ohrc-page-h4'>Background info</h4>

            <div class='ohrc-box'>
                <p>The database provides easy access to country specific
                    human rights information emanating from
                    international human rights mechanisms</p>
                <a href="content/background-info?iframe=no" class="read-more">more &gt;&gt;</a>
            </div>
        </div>
    </div>
    <div class='col-md-4'>
        <div style='width:100%;'>
            <?php
            print get_discussions();
            ?>
        </div>
    </div>
</div>
<div class='row'>
    <div class='col-md-12'>
        <div style='margin-left:auto;margin-right:auto;width:30%'>
            <a id='ohrc-logo' href='http://www.ohchr.org' style='margin-left:auto;margin-right:auto;width:80%'><img
                    src='<?php echo $base_url; ?>/sites/all/themes/Sarai/images/ohrc.jpg'/></a>
        </div>
    </div>
</div>