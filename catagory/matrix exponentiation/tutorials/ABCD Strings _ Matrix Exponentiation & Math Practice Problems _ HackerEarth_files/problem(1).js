// Global variable for the test timer
function leadingZero(a){return a<10?"0"+a:+a}function timeHandler(){this.dElem=$("#days"),this.hElem=$("#hours"),this.mElem=$("#mins"),this.sElem=$("#secs"),this.updateTime=function(a){this.days=Math.floor(a/86400),a-=this.days*86400,this.hours=Math.floor(a/3600),a-=this.hours*3600,this.mins=Math.floor(a/60),a-=this.mins*60,this.secs=a},this_ctx=this,eventStarted=$(".time-box").attr("started"),eventStarted=="False"?this.eventStarted=!1:this.eventStarted=!0;var a=Number($(".time-box").attr("time"));this.updateTime(a),this.setTime=function(){this.dElem.html(leadingZero(this.days)),this.hElem.html(leadingZero(this.hours)),this.mElem.html(leadingZero(this.mins)),this.sElem.html(leadingZero(this.secs)),this.days>0&&$("#day-box").show()},this.updateTimer=function(){var b=Number($("#days").html()),c=Number($("#hours").html()),d=Number($("#mins").html()),e=Number($("#secs").html());e-=1,e==-1&&(d-=1,e=59,d==-1&&(c-=1,d=59,c==-1&&(b-=1,c=23,b==-1&&(b=0,c=0,d=0,e=0)))),this.days=b,this.hours=c,this.mins=d,this.secs=e,$("#days").html(leadingZero(this.days)),$("#hours").html(leadingZero(this.hours)),$("#mins").html(leadingZero(this.mins)),$("#secs").html(leadingZero(this.secs)),this.days==0&&$("#day-box").hide();if(b==0&&c==0&&d==0&&e==0){clearInterval(testIntervalTimer),clearInterval(syncIntervalTimer);var f=$(".time-box").attr("finish-url");typeof f!="undefined"&&$.ajax({type:"POST",url:f,dataType:"json",success:function(b){b["status"]=="OK"&&(b.ended?(alert("The time has completed!"),window.location=$(".time-box").attr("complete-url")):(a=b.left,this_ctx.updateTime(a)))}})}},this.syncTimer=function(){var b=$(".time-box").attr("finish-url");$.ajax({type:"POST",url:b,dataType:"json",success:function(b){b["status"]=="OK"&&(b.ended?(alert("The time has completed!"),window.location=$(".time-box").attr("complete-url")):(a=b.left,this_ctx.updateTime(a),$("#days").html(leadingZero(this_ctx.days)),$("#hours").html(leadingZero(this_ctx.hours)),$("#mins").html(leadingZero(this_ctx.mins)),$("#secs").html(leadingZero(this_ctx.secs))))}})},this.startTimer=function(){this.eventStarted&&(testIntervalTimer=setInterval(this.updateTimer,1e3))},this.startSync=function(){this.eventStarted&&(syncIntervalTimer=setInterval(this.syncTimer,12e4))},this.init=function(){this.setTime(),this.startTimer(),this.startSync()}}function updateProblemsTable(a){$("#"+a.solved_by_html_id).html(a.solved_by_count),$("#"+a.accuracy_html_id).html(a.accuracy_percentage),$("#"+a.accuracy_html_id).attr("title",a.accuracy),$("#"+a.accuracy_html_id).tipTip({defaultPosition:"top"}),a.languages||(a.languages="..."),$("#"+a.languages_html_id).html(a.languages)}var testIntervalTimer=0,this_ctx;$(".comment-form textarea").watermark("Comment"),$(".comment-form textarea").elastic();var questionTimer=function(){var a=$("#progress-bar");if(a.length>0){var b=!1,c=a.attr("time"),d=0,e=a.attr("form_id"),f=$("#"+e+""),g=c;a.html(g);var h=function(){g>0?(g-=1,a.html(g)):b||(b=!0,f.submit())},i=setInterval(h,1e3)}};$(document).ready(function(){var a=new timeHandler;a.init(),$("body").click(function(a){var b=$(a.target),c=$(".problem-list-wrapper");if(c.is(":hidden"))if(b.is("#problems")){var d=b.position(),e=27,f=d.left-70;c.css({bottom:e+"px",left:f+"px"}),c.show()}else c.hide();else c.hide()}),$(".revision a").click(function(){var a=$(this).attr("ajax"),b=$(this);return a&&$.post(a,function(){b.parent().addClass("starred")}),!1}),questionTimer()});