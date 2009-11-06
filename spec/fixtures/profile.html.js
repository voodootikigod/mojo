'<h2>' + (Mojo.escape(Mojo.normalize(o.name))) + '</h2>\n\
' + Mojo.enumerate(o, Mojo.normalize(o.biography), function(o){
    return '\n\
  <h3>Bio</h3>\n\
  <p>' + (Mojo.escape(Mojo.normalize(o.biography))) + '</p>\n\
'}) + ''