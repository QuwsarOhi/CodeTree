/**
 * jQuery TextExt Plugin
 * http://textextjs.com
 *
 * @version 1.3.1
 * @copyright Copyright (C) 2011 Alex Gorbatchev. All rights reserved.
 * @license MIT License
 */(function(a){function b(){}a.fn.textext.TextExtFocus=b,a.fn.textext.addPlugin("focus",b);var c=b.prototype,d="html.focus",e={html:{focus:'<div class="text-focus"/>'}};c.init=function(a){var b=this;b.baseInit(a,e),b.core().wrapElement().append(b.opts(d)),b.on({blur:b.onBlur,focus:b.onFocus}),b._timeoutId=0},c.onBlur=function(a){var b=this;clearTimeout(b._timeoutId),b._timeoutId=setTimeout(function(){b.getFocus().hide()},100)},c.onFocus=function(a){var b=this;clearTimeout(b._timeoutId),b.getFocus().show()},c.getFocus=function(){return this.core().wrapElement().find(".text-focus")}})(jQuery);