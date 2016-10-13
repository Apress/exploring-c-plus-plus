/** @file list6004.cpp */
/** Listing 60-4. Using Smart Pointers to Manage Artifacts */
std::map<std::string, std::tr1::shared_ptr<artifact> > artifacts;

std::tr1::shared_ptr<artifact>
lookup_artifact(std::string const& name)
{
  std::tr1::shared_ptr<artifact> a(artifacts[name]);
  if (a.get() == 0)
  {
    a.reset(new artifact(name));
    artifacts[name] = a;
  }
  return a;
}
