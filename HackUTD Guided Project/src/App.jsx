import Navbar from "./components/Navbar";
import FeaturedItem from "./components/FeaturedItem";
import Dashboard from "./components/Dashboard";
import React from "react";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import MapPage from "./pages/MapPage";
import ActivityPage from "./pages/ActivityPage";
import RsvpPage from "./pages/RsvpPage";

function App() {
return (
  <Router>
    {/* Regardless of what page we're on, we ALWAYS render the Navbar */}
    <Navbar />
    <Routes>
      {/* Home route displaying Navbar, FeaturedItem, and Dashboard */}
      <Route
        path="/"
        element={
          <>
            <FeaturedItem />
            <Dashboard />
          </>
        }
      />
      {/* Browse route displaying Navbar and BrowsePage */}
      <Route path="/map" element={<MapPage />} />
      <Route path="/activity" element={<ActivityPage />} />
      <Route path="/rsvp" element={<RsvpPage />} />
    </Routes>
  </Router>
);
}

export default App;