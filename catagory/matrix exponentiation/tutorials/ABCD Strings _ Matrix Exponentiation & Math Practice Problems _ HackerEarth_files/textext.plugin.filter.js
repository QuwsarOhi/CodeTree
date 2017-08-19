/**
 * jQuery TextExt Plugin
 * http://textextjs.com
 *
 * @version 1.3.1
 * @copyright Copyright (C) 2011 Alex Gorbatchev. All rights reserved.
 * @license MIT License
 */(function(a){function b(){}a.fn.textext.TextExtFilter=b,a.fn.textext.addPlugin("filter",b);var c=b.prototype,d="filter.enabled",e="filter.items",f={filter:{enabled:!0,items:null}};c.init=function(a){var b=this;b.baseInit(a,f),b.on({getFormData:b.onGetFormData,isTagAllowed:b.onIsTagAllowed,setSuggestions:b.onSetSuggestions}),b._suggestions=null},c.onGetFormData=function(a,b,c){var d=this,e=d.val(),f=e,g="";d.core().hasPlugin("tags")||(d.isValueAllowed(f)&&(g=e),b[300]=d.formDataObject(f,g))},c.isValueAllowed=function(a){var b=this,c=b.opts("filterItems")||b._suggestions||[],e=b.itemManager(),f=!b.opts(d),g;for(g=0;g<c.length&&!f;g++)e.compareItems(a,c[g])&&(f=!0);return f},c.onIsTagAllowed=function(a,b){b.result=this.isValueAllowed(b.tag)},c.onSetSuggestions=function(a,b){this._suggestions=b.result}})(jQuery);