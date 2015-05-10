function sr_hide1() {
//jQuery('#iframe-dashboard').contents().find('#edit-field-sr-mandate').css('display','none');
    jQuery('#edit-field-sr-mandate').hide();
}
function sr_show1() {
//jQuery('#iframe-dashboard').contents().find('#edit-field-sr-mandate').css('display','block');
    jQuery('#edit-field-sr-mandate').show();
}
function sr_hide2() {
//jQuery('#iframe-dashboard').contents().find('#edit-field-sr-mandate').css('display','none');
    jQuery('#edit-field-other-means-of-verificatio').hide();
}
function sr_show2() {
//jQuery('#iframe-dashboard').contents().find('#edit-field-sr-mandate').css('display','block'); 
    jQuery('#edit-field-other-means-of-verificatio').show();
}
function sr_overlay(){
    jQuery('ol.breadcrumb').html("<li></li>");
    jQuery("h1#overlay-title").hide();
}
jQuery(document).ready(function() {
    sr_hide1();
    sr_hide2();
    sr_overlay();
    jQuery('#edit-field-mechanism').on("change", function() {
        var val = jQuery('#edit-field-mechanism-und').attr('value');
        if (val == 13) {
            sr_show1();
        }
        else {
            sr_hide1();
        }
    });
    
    jQuery('#edit-field-means-of-verification-und').on("change", function() {
        var val = jQuery('#edit-field-means-of-verification-und').attr('value');
        if (val == 808) {
            sr_show2();
        }
        else {
            sr_hide2();
        }
    });
}
);
