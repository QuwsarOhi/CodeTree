/**
 * jQuery TextExt Plugin
 * http://textextjs.com
 *
 * @version 1.3.1
 * @copyright Copyright (C) 2011 Alex Gorbatchev. All rights reserved.
 * @license MIT License
 */(function(a){function b(){}a.fn.textext.TextExtSuggestions=b,a.fn.textext.addPlugin("suggestions",b);var c=b.prototype,d="suggestions",e={suggestions:null};c.init=function(a){var b=this;b.baseInit(a,e),b.on({getSuggestions:b.onGetSuggestions,postInit:b.onPostInit})},c.setSuggestions=function(a,b){this.trigger("setSuggestions",{result:a,showHideDropdown:b!=0})},c.onPostInit=function(a){var b=this;b.setSuggestions(b.opts(d),!1)},c.onGetSuggestions=function(a,b){var c=this,e=c.opts(d);e.sort(),c.setSuggestions(c.itemManager().filter(e,b.query))}})(jQuery);