'<html>\n\
  <head>\n\
    <title>' + (Mojo.escape(o.title)) + '</title>\n\
  </head>\n\
  <body>\n\
    <h1>' + (Mojo.escape(o.title)) + '</h1>\n\
    ' + Mojo.enumerate(o, o.articles, function(o){
    return '\n\
      <div class="article">\n\
        <h2>' + (Mojo.escape(o.title)) + '</h2>\n\
        <p>' + (Mojo.escape(o.body)) + '</p>\n\
        ' + Mojo.enumerate(o, o.published, function(o){
    return '\n\
          <p>' + (Mojo.escape(o.title)) + ' is published</p>\n\
        '}) + '\n\
      </div>\n\
    '}) + '\n\
  </body>\n\
</html>'