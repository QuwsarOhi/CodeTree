/**
 * jQuery TextExt Plugin
 * http://textextjs.com
 *
 * @version 1.3.1
 * @copyright Copyright (C) 2011 Alex Gorbatchev. All rights reserved.
 * @license MIT License
 */(function(a){function b(){}a.fn.textext.TextExtArrow=b,a.fn.textext.addPlugin("arrow",b);var c=b.prototype,d="html.arrow",e={html:{arrow:'<div class="text-arrow"/>'}};c.init=function(b){var c=this,f;c.baseInit(b,e),c._arrow=f=a(c.opts(d)),c.core().wrapElement().append(f),f.bind("click",function(a){c.onArrowClick(a)})},c.onArrowClick=function(a){this.trigger("toggleDropdown"),this.core().focusInput()}})(jQuery);