#include "dbimpl.h"
#include "option.h"

int main()
{
	Options options;
	options.createIfMissing = true;
	DBImpl db(options,"db");
	Status s = db.open();
	assert(s.ok());

	for(int i = 0 ; i < 1; i++)
	{
		std::string key = std::to_string(i);
		std::string value = std::to_string(i);
		std::string v;
		s = db.put(WriteOptions(),key,value);
		assert(s.ok());
		s = db.get(ReadOptions(),key,&v);
		assert(s.ok());
	}
	return 0;
}