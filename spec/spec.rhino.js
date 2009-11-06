
load('/Library/Ruby/Gems/1.8/gems/jspec-2.11.10/lib/jspec.js')
load('lib/mojo.js')

JSpec
.exec('spec/mojo.spec.js')
.run({ formatter: JSpec.formatters.Terminal })
.report()