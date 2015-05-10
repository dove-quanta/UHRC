
function disable_fields() {
    /*jQuery('#edit-field-recommendation-und-0-value').prop('readonly', 'true');
    jQuery('#edit-field-year-und-0-value-year').prop('readonly', 'true');
    jQuery('#edit-field-next-state-deadline-und-0-value-year').prop('readonly', 'true');
    jQuery('#edit-field-thematic-area-und').prop('readonly', 'true');
    jQuery('#edit-field-mechanism-und').prop('readonly', 'true');
    jQuery('#edit-field-sr-mandate-und-0-value').prop('readonly', 'true');
    jQuery('select#edit-field-responsible-mda-und').prop('readonly', 'true');
    jQuery('select#edit-field-contributing-mda-und').prop('readonly', 'true');
    //jQuery('#edit-field-indicators-und-0-value').prop('readonly', 'true');
    //jQuery('#edit-field-baseline-und-0-value').prop('readonly', 'true');
    //jQuery('#edit-field-target-und-0-value').prop('readonly', 'true');*/
    jQuery('ol.breadcrumb').html("<li>You are authorized to edit your indicators, baseline, target, means of verification and status of implementation – please scroll down to start editing your data</li>");
    jQuery("h1#overlay-title").hide();
}
jQuery(document).ready(function() {
    disable_fields();
});
