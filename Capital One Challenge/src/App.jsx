import React from 'react'
import Topbar from './components/Topbar.jsx'
import Mainpage from './components/Mainpage.jsx'
import CreditCalc from './components/CreditCalc.jsx'
import ChallengePage from './pages/ChallengePage.jsx'
import CreditScorePage from './pages/CreditScorePage.jsx'

function App() 
{
  return (
    <div>
      <Topbar />
      <Mainpage />
      <CreditCalc />
      <ChallengePage />
      <CreditScorePage />

    </div>
  )
}

export default App