import data from "../data/data.json";
import Card from "./card";

function Dashboard() {
  // console.log(data); <- We don't need to log the data anymore
  // Insert state to store items, initialized with data from JSON file
  return (
    <div className="relative my-12 flex flex-col items-center">
      {/* TITLE */}
      <h1 className="poppins-bold flex-row text-2xl">Who's Invited?</h1>
      <hr className="mb-4 mt-2 w-1/3 border-black" />

      {/* Event List Grid */}
      <div className="relative z-10 grid sm:grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-6">
        {/* Map through objects and render a Card component for each */}
        {data.map((object) => (
          <Card
            key={object.id}
            name={object.name}
            img={object.img}
            status={object.status}
            bringing={object.bringing}
          />
        ))}
      </div>
    </div>
  );
}

export default Dashboard;
