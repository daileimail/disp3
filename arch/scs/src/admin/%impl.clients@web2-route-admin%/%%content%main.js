rootApp.factory('access', function(req, auth){
	var methods = {};
	methods.saveUpload = function(path, obj, pobj, key){		
		methods.upload(path, obj, function(err, result){
			if(err) return;
			pobj[key] = result.filename;
		});
	}
	methods.upload = function(path, obj, fn){
		req.postBearerFile("/api/upload/" + path, auth.gettoken(), obj, function(err, result){
			fn(err, result);
		});
	}
	methods.delete = function(schema, _id, fn){
		req.postBearer("/api/access/"+schema+"/delete", auth.gettoken(), {where: {_id: _id}}, function(err, result){
			if(fn) fn(err, result);
		});
	}
	methods.select = function(schema, where, fn){
		if(typeof where != "object") where = {_id: where};
		req.postBearer("/api/access/"+schema+"/select", auth.gettoken(), {where: where}, function(err, result){
			if(fn) fn(err, result);
		});
	}
	methods.update = function(schema, _id, json, fn){
		req.postBearer("/api/access/"+schema+"/update", auth.gettoken(), {where: {_id: _id}, options: json}, function(err, result){
			if(fn) fn(err, result);
		});
	}
	methods.insert = function(schema, json, fn){
		req.postBearer("/api/access/"+schema+"/insert", auth.gettoken(), {where: json}, fn);
	}
	methods.export = function(schema, _id){
		req.postBearer("/api/access/"+schema+"/delete", auth.gettoken(), {_id: _id}, function(err){
			if(!err) alert("success");
		});
	}
	return methods;
});
