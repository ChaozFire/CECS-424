var fs = require('fs');
var readline = require('readline');
var instream = fs.createReadStream(process.argv[2]);
var outstream = new (require('stream'))();
var rl = readline.createInterface(instream,outstream);
var regex = '^[$][*]*'
+ '([0]|([1-9][\\d]{2}|[1-9][\\d]|[1-9])([,][\\d]{3})*)'
+ '([.][\\d]{2})?$';

rl.on('line', function(line) {
  if(line.match(regex)) {
    console.log('Matched: ' + line)
  }
  else {
    console.log("Not matched: " + line)
  }
});
rl.on('close', function(line) {
  
})
