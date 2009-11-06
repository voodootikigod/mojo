'<html>\n\
  <head>\n\
    <title>' + (Mojo.escape(Mojo.normalize(o.title))) + '</title>\n\
  </head>\n\
  <body>\n\
    <h1>' + (Mojo.escape(Mojo.normalize(o.title))) + '</h1>\n\
    ' + Mojo.enumerate(o, Mojo.normalize(o.articles), function(o){
    return '\n\
      <div class="article">\n\
        <h2>' + (Mojo.escape(Mojo.normalize(o.title))) + '</h2>\n\
        <p>' + (Mojo.escape(Mojo.normalize(o.body))) + '</p>\n\
        ' + Mojo.enumerate(o, Mojo.normalize(o.published), function(o){
    return '\n\
          <p>' + (Mojo.escape(Mojo.normalize(o.title))) + ' is published</p>\n\
        '}) + '\n\
      </div>\n\
    '}) + '\n\
  </body>\n\
</html>'