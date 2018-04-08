This project is only for insane people right?<br />
No of course it isn't. This is a program meant for use by console developers.<br />
It's meant to be a tool used to easilly find and use console projects made by others.<br />
And you can use it to create console websites too.<br />
Why you ask? Why not use github?<br />
<br />
Well if you want a console project from github then there are a lot of steps involved.<br />
<br />
First you must find a console project.<br />
Then you must download it.<br />
After that you must compile the code.(And hope that it works)<br />
And then you can finally run it.<br />
It would be a lot easier if you could search for it and instantly run the program.<br />
<br />
Also this project involves console websites we also aim to create a custom console Markup Language.<br />
Here's how it will work.<br />
<br />
First you need to define your tags in a .def file.<br />
Like this:<br />
<br />
style.def<br />
<br />
\<p> = {<br />
  type: TEXT;<br />
  fontColour: RED;<br />
  backColour: GREEN;<br />
}<br />
<br />
\<a> = {<br />
  type: LINK;<br />
  fontColour: WHITE;<br />
  backColour: BLUE;<br />
}<br />
<br />
After that you can create your website in a .chtml file.<br />
like this:<br />
<br />
index.chtml<br />
<br />
@import "style.def"<br />
<br />
\<p>This text is RED with a GREEN background\</p><br />
<br />
\<a>youtube.com;This link is WHITE on BLUE and take you to youtube\</a><br />
<br />
\<text>This hasn't been defined so it'll be plain white on black text\</text><br />
<br />
As you can see it looks a bit like HTML. But the major difference is that in this markup language it's easy to create your own tags.<br />
<br />
And if you're interested to know how the sharing of project will work well let me give you a brief explanation.<br />
<br />
First you'll need to make a console project.<br />
Then you'll need to get a domain and make a website.<br />
(It doesn't need to be complicated. You can litterally only put the title of the program on the page)<br />
Then upload your page and program.<br />
And now everybody can find and run it.<br />
<br />
As you can see it's a bit more work to upload your project.<br />
But it's a lot easier for other people to find your program.<br />
<br />
If you're interested to help let me know. Everyone is welcome to help us out.<br />
