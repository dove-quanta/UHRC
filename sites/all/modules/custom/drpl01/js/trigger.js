function search()
{
    var iframes=["iframe-mechanism","iframe-year-received","iframe-thematic-area","iframe-mda"];
    var query="";
    for(var i=0; i<iframes.length; i++){
        var checked=jQuery('#'+iframes[i]).contents().find("form input:checked");
        var subquery="";
        for(var j=0; j<checked.length; j++){
            subquery=subquery+checked[j].id+",";
        }
        query=query+subquery+"|";
    }
    var url=jQuery("#iframe-recommendation-grid").attr('src').split('&SEARCH');
    jQuery("#iframe-recommendation-grid").attr("src",url[0]+"&SEARCH="+query);
}
function search2()
{
    var iframes=["iframe-mechanism","iframe-year-received","iframe-thematic-area","iframe-mda"];
    var query="";
    for(var i=0; i<iframes.length; i++){
        var checked=jQuery('#'+iframes[i]).contents().find("form input:checked");
        var subquery="";
        for(var j=0; j<checked.length; j++){
            subquery=subquery+checked[j].id+",";
        }
        query=query+subquery+"|";
    }
    key=jQuery('#ohrc-refine').attr('value');
    jQuery("#iframe-recommendation-grid").attr("src","recommendation-grid?SEARCH="+query+'&mSearch='+key);
}

