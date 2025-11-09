import React from "react";
import Navbar from "../components/Navbar";
import WeatherComponent from "../components/WeatherComponent";
import VoteComponent from "../components/VoteComponent";
function ActivityPage() {
  return (
    <div>
      <div className="relative my-12 flex flex-col items-center">
        <h1 className="poppins-bold text-blue-400">Weather</h1>
        <hr className="mb-6 mt-2 w-1/3" />

        <div className="relative z-10 p-6 w-full max-w-2xl flex flex-col gap-6">
          <WeatherComponent />
          <VoteComponent />
        </div>
      </div>
    </div>
  );
}
export default ActivityPage;
