
// Load required packages
var passport = require('passport');
var db= require("../core/db");
var BearerStrategy = require('passport-http-bearer').Strategy;
function check(token, done) {
  db.getModel("^^=userdb$$").select({
    token: token
  }, function (err, user) {
    if (err) { return done(err); }
    if (!user) { return done(null, false); }
    ^^=rule$$
    return done(null, user, { scope: 'all' });
  });
}
passport.use("default", new BearerStrategy(check));

module.exports.check = check;
var midwares = {};
midwares["default"] = passport.authenticate('default', { session: false });
module.exports.midware = midwares["default"];
^^for(var fi=0; fi<local.authflags.length;fi++){var authflag = authflags[fi];$$
midwares["^^=authflag$$"] = function(req, res, next){
	if(!req.user["^^=authflag$$"]) return next(req, res);
	else res.status(401).send("");
	
}
^^}$$
module.exports.midwares = midwares;
