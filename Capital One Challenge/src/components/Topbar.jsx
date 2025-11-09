// Topbar.jsx
import React from "react";

function Topbar() {
  return (
    <>
      <div className="flex flex-row items-center px-20 py-4 bg-white">
        {/* TITLE */}
        <img className="w-40" src="/images/capital-one.png" />

        {/* PAGES */}
        <Link to="/Challenge" className="text-black text-sm px-10 poppins-semibold hover:text-gray-500 hover:scale-105 transition duration-300 ">
          Capital One Challenge
        </Link>

        <div className="flex flex-row text-sm gap-10 poppins-semibold text-black">
          <Link to="/CreditScore" className="hover:text-gray-500 hover:scale-105 transition duration-300">
            Credit Score
          </Link>
        </div>
      </div>
      {/* Horizontal line separator */}
      <hr className="w-full border-t-1 border-black border-opacity-50" />
    </>
  );
}

export default Topbar;
