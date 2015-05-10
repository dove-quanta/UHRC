
function changeHeight(id){
    var l0=jQuery("#"+id).length;
    var l1=parent.jQuery("#"+id).length;
    if(l0>0){
        var height=jQuery("#"+id).contents().find("body").height();
        jQuery("#"+id).attr('style','height:'+height+'px');
        
    }
    if(l1>0){        
       // var height=parent.jQuery("#"+id).contents().find("body").height();
       // parent.jQuery("#"+id).attr('style','height:'+height+'px');
    }
}

