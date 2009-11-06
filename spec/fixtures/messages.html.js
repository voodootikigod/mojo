'<ul>\n\
  ' + Mojo.enumerate(o, Mojo.normalize(o), function(o){
    return '\n\
    <li>' + (Mojo.escape(Mojo.normalize(o))) + '</li>\n\
  '}) + '\n\
</ul>'